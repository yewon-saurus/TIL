const input = require('fs').readFileSync('input.txt').toString().trim().split('\n');
const sentense = input[0];
const wantSearch = input[1];

console.log(sentense.indexOf(wantSearch));