const unsorted = require('fs').readFileSync('input.txt').toString().trim().split(' ');
let sorted = "";

sorted = unsorted
  .sort(function(a, b) {
    return a - b;
  })
  .join(" ");

console.log(sorted);