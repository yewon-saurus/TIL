const input = require('fs').readFileSync('input.txt').toString().trim().split(/\s/);

const a = input.slice(0, (input.length/2));
const b = input.slice(input.length/2 + 1);
const stu = {};

console.log(a[1], b[1]);

for (var i = 0; i < a.length; i++) {
    stu[a[i]] = parseInt(b[i], 10);
}

console.log(stu);