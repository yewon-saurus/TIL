const jumsu = require('fs').readFileSync('input.txt').toString().trim().split(' ').map((n) => {
    return parseInt(n, 10);
});

jumsu.sort((a, b) => {
    return a - b;
})

let count = 0;
let arr = [];

while (arr.length < 3) {
    let n = jumsu.pop();
    if (!arr.includes(n)) {
        arr.push(n);
    }
    count++;
}

console.log(count);