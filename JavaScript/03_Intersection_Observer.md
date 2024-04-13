# Intersection Observer

'scroll event'는 성능에 악영향을 줄 수 있다!

- 스크롤 시 짧은 시간 내에 수 백, 수 천의 이벤트가 **동기적**으로 실행될 수 있다는 점
- 페이지 내의 여러 개의 요소가 각자 각기의 목적으로(광고, 레이지 로딩, 무한 스크롤 등) scroll event를 리스닝 하는 경우에는, 이에 상응하는 callback이 무수히 실행될 수 있다는 점

때문에, 메인 스레드에 큰 부하를 줄 수 있다는 것이죠

(단, Intersection Observer에도 한계가 있어서.. 어떤 경우에는 전통적인 scroll event 로직이 적합하다는 것은 기억해 두자)

**스크롤 관련 루틴이 실무에서 많이 쓰이고 있으므로**, 신뢰도 있는 공식 API가 필요했는데.. 2016년 4월에 구글 개발자 페이지를 통해 소개되었다고 합니다

그리고, 'getBoundingClientRect'라는 애도 있는데, 얘는 'reflow`를 발생시킬 수 있다고 합니다..

아무튼 `Intersection Observer API`는 '루트 요소'와 '타겟 요소'의 교차점을 관찰해 "교차하는지 아닌지"를 구별하게 되는데요,

- scroll event와 다르게, **비동기적**으로 실행되며
- getBoundingClientRect와 다르게, **reflow를 발생시키지 않는다**

따라서 여러모로 성능 상 유리하다고 합니다.

## 교차성(가시성)을 계산하는 방법 (유념하기)

Intersection Observer는 모든 영역을 rectangle로 취급하는데요

요소가 사각형이 아니거나, 이외 불규칙한 모습으로 렌더링 되었다고 하더라도,

**요소의 모든 부분을 감싸는 가장 작은 사각형으로 가정**하고 교차성(가시성)을 계산하는 것입니다

이를 유념하면서 다음을 이해해 봅시다!

## 사용법 (code snippet)

```js
let options = {
    root: document.querySelector('#scrollArea'),
    rootMargin: '0px',
    threshold: 1.0,
}

let observer = new IntersectionObserver(callback, options);

let target = document.querySelector('#listItem');

observer.observe(target);
```

1. `new` 키워드를 통해 인스턴스를 생성
2. `callback`, `options` 파라미터 넣어주기


여기서 callback은 '가시성의 변화가 생겼을 때' 호출되는 함수를 넣어주면 되는 것이지요

그럼 options는요?

### options

여러가지 설정 요소가 있는 것 같은데..

- root

타겟 요소의 가시성을 확인할 때 사용되는 '루트 요소' 입니다. 이것은 '타겟 요소의 조상 요소' 이어야 합니다. 설정하지 않거나, 값을 null로 주었을 때는 기본값으로 '브라우저 뷰포트'가 설정됩니다.

- rootMargin

`margin`은 제가 아는 그 margin이 맞습니다. 루트 요소의 **범위를 확장**할 수 있습니다. 즉, 확장된 영역 안에 타겟 요소가 들어가면 가시성에 변화가 생깁니다. CSS와 유사하게 top, right, bottom, left의 margin을 각각 설정할 수 있습니다. 기본값은 0이며, 설정 시 단위를 꼭 입력해야 합니다. (아무래도 그럴 것 같죠?)

- threshold

콜백이 실행될 타겟 요소의 '가시성 퍼센티지'를 설정합니다. 값으로는 '단일 숫자' 및 '숫자 배열'이 들어갈 수 있습니다. 즉, 요소의 top, bottom이 노출된 순간만 콜백을 실행할 수 있는 게 아니라, **타겟 요소가 어느정도(퍼센티지) 보여졌는지에 따라** 콜백을 호출할 수 있는 것입니다!

```js
// 타겟 요소가 50% 가시성이 확인되었을 때
let observer1 = new IntersectionObserver(callback, {
	threshold: 0.5
});

// 타겟 요소가 25% 단위로 가시성이 확인되었을 때
let observer1 = new IntersectionObserver(callback, {
	threshold: [0, 0.25, 0.5, 0.75, 1]
});
```

### callback

타겟 요소의 관찰이 시작되거나, 가시성에 변화가 감지되면(threshold와 만나면..) 등록된 callback이 실행됩니다.

다음 code snippet을 보시면..

```js
let callback = (entries, observer) => {
  entries.forEach(entry => {
    // 각 entry는 가시성 변화가 감지될 때마다 발생하고 그 context를 나타냅니다.
    // target element:
    //   entry.boundingClientRect
    //   entry.intersectionRatio
    //   entry.intersectionRect
    //   entry.isIntersecting
    //   entry.rootBounds
    //   entry.target
    //   entry.time
  });
};
```

파라미터로 `entries`와 `observer`를 받고 있는 callback 함수의 모습인데요

- entries

얘는 IntersectionObserverEntry 인스턴스를 담은 배열입니다. 일반적으로 callback에 파라미터로 전달이 되고, `Intersection Observer.tackRecords()`를 통해 반환받을 수도 있습니다. IntersectionObserverEntry는 루트 요소와 타겟 요소의 '교차(threshold와 만났을 때)'의 상황을 묘사하는데, 포함된 property는 모두 read only 입니다.

- `IntersectionObserverEntry.boundingClientRect`
- `IntersectionObserverEntry.intersectionRect`
- `IntersectionObserverEntry.intersectionRatio`
- `IntersectionObserverEntry.isIntersecting`
- `IntersectionObserverEntry.rootBounds`
- `IntersectionObserverEntry.target`
- `IntersectionObserverEntry.time`

## Methods

- `IntersectionObserver.observe(targetElement)`: 타겟 요소에 대한 관찰을 시작합니다.
- `IntersectionObserver.unobserver(targetElement)`: 타겟 요소에 대한 관찰을 중지합니다. 관찰의 목적이 이루어진 이후에 굳이 관찰을 할 필요가 없는 요소들에 대한 모든 관찰을 중지합니다.
- `InterectionObserver.disconnect()`: 인스턴스의 타겟 요소들에 대한 모든 관찰을 중지합니다.
- `IntersectionObserver.takeRecords(targetElement)`: `IntersectionObserverEntry` 인스턴스들의 배열을 return 합니다.

# 참고할 추가 내용

[MDN Intersection Observer API](https://developer.mozilla.org/ko/docs/Web/API/Intersection_Observer_API)
