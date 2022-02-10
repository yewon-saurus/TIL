const name = require("fs").readFileSync('input.txt').toString().split('\n');

console.log(name[0].toUpperCase());