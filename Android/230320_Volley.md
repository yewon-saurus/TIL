# Volley

## Volley 개요

🔗[Volley 개요 :: developers.android.com](https://developer.android.com/training/volley?hl=ko)

Volley는 Android 앱의 네트워킹을 더 쉽고, 무엇보다도 더 빠르게 하는 HTTP 라이브러리 입니다.

Volley는 GitHub에서 사용할 수 있습니다..

Volley를 사용하면 다음과 같은 이점이 있습니다.

- 네트워크 요청의 자동 예약

- 여러 개의 동시 네트워크 연결

- 표준 HTTP 캐시 일관성을 갖춘 투명한 디스크 및 메모리 응답 캐싱

- 요청 우선순위 지정 지원

- 취소 요청 API. 단일 요청을 취소하거나 취소할 요청의 블록 또는 범위 설정 가능

- 용이한 맞춤 설정(예: 재시도, 백오프)

- 강력한 정렬 기능 -> 네트워크에서 비동기식응로 가져온 데이터로 UI를 올바로 채우는 작업을 쉽게 실행 가능

- 디버깅 및 추적 도구

Volley는 UI를 채우기 위해 사용되는 RPC 유형 작업(ex: 검색결과 페이지를 구조화된 데이터로 가져오기)에 탁월합니다. 모든 프로토콜과 쉽게 통합되며 원시 문자열, 이미지 및 JSON 지원을 즉시 사용할 수 있습니다. 필요한 기능에 대한 기본 자원을 제공하여 사용자의 앱에 맞는 로직에 집중할 수 있습니다.

..네?

Volley는 파싱하는 동안 모든 응답을 메모리에 유지하므로 대규모 다운로드 또는 스트리밍 작업에는 적합하지 않습니다. 대규모 다운로드 작업은 `DownloadManager`와 같은 대안을 사용하는 것이 좋습니다.

Volley를 프로젝트에 추가하는 가장 쉬운 방법은 앱의 `build.gradle` 파일에 다음과 같은 종속 항목을 추가하는 것입니다.

```
    dependencies {
        ...
        implementation 'com.android.volley:volley:1.1.1'
    }
    
```

## 간단한 요청 보내기

🔗[간단한 요청 보내기 :: developers.android.com](https://developer.android.com/training/volley/simple?hl=ko#java)

고급 단계에서는 `RequestQueue`를 만들고 `Request` 객체를 전달하여 Volley를 사용합니다.

`RequestQueue`는 네트워크 작업 실행, 캐시 읽고 쓰기 및 응답 파싱을 위해 스레드를 관리합니다.

요청은 원시 응답을 파싱하고 Volley는 전송을 위해 파싱된 응답을 기본 스레드로 돌려보냅니다.

..네??

### 인터넷 권한 추가

Volley를 사용하려면 앱의 매니페스트에 `android.permission.INTERNET` 권한을 추가해야 합니다.

이렇게 하지 않으면, 앱이 네트워크에 연결할 수 없거든요!

### newRequestQueue 사용

Volley는 기본값으로 `RequestQueue`를 설정하고 큐를 시작하는 편리한 `Volley.newRequestQueue` 메서드를 제공합니다..

예:

```java
    final TextView textView = (TextView) findViewById(R.id.text);
    // ...

    // Instantiate the RequestQueue.
    RequestQueue queue = Volley.newRequestQueue(this);
    String url ="http://www.google.com";

    // Request a string response from the provided URL.
    StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
        @Override
        public void onResponse(String response) {
            // Display the first 500 characters of the response string.
            textView.setText("Response is: "+ response.substring(0,500));
        }
    }, new Response.ErrorListener() {
        @Override
        public void onErrorResponse(VolleyError error) {
            textView.setText("That didn't work!");
        }
    });

    // Add the request to the RequestQueue.
    queue.add(stringRequest);
    
```

Volley에서는 항상 기본 스레드에서 파싱된 응답을 전달합니다.

- ..아무튼, `Volley.newRequestQueue` 메서드가 있으니까, 직접 `RequestQueue`를 설정하지 않아도 된다는 거죠

### 요청 보내기

요청을 보내려면, 위와 같이 일단 요청을 생성한 후 -> `add()`로 `RequestQueue`에 추가해야

요청을 추가하면 요청이 파이프라인을 통해 이동하고 처리되며 원시 응답이 파싱되어 전달됩니다.

### 요청 취소

요청을 취소하려면, `Request` 객체의 `cancle()`을 호출합니다.

요청이 취소되면 Volley에서 요청 핸들러가 호출되지 않도록 보장합니다. 실제로 이 작업은 활동의 `onStop()` 메서드에서 대기 중인 요청을 모두 취소할 수 있고 `onSaveInstanceState()` 또는 다른 방어적인 상용구 호출과 관계없이 `getActivity() == null` 검사로 응답 핸들러를 혼란스럽게 하지 않아도 되는 것을 의미합니다.

....네에?
