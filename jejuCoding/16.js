const input = require("fs").readFileSync('input.txt').toString().split('');

// for (let i = 2; i >= 0; i--) {
//     process.stdout.write(input[i]);
// }

const reverse = input.reverse().join('');
console.log(reverse);