const tall = require("fs").readFileSync('input.txt').toString().split('\n');

if (tall[0] >= 150) {
    console.log('YES');
}
else {
    console.log('NO');
}