var arr = [200, 100, 300];

arr.splice(2, 0, 10000);

console.log(arr);

//

var test = [1, 3, 5, 7, 9]

test.splice(1, 0, 100)
console.log(test)

test.splice(2, 1, 200)
console.log(test)

test.splice(6, 0, 300)
console.log(test)

//

var test2 = [1, 2]

test2.splice(2, 0, 400)
console.log(test2)