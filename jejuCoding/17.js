const tall = require('fs').readFileSync('./jejuCoding/input17.txt').toString().split('\n');

if (tall[0] >= 150) {
    console.log('YES');
}
else {
    console.log('NO');
}