const r = require('fs').readFileSync('input.txt').toString().split('');

function calcCircleArea(r) {
    return r * r * 3.14
}

console.log(calcCircleArea(r));