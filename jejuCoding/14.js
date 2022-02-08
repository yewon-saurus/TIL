const n = require('fs').readFileSync('./jejuCoding/input14.txt').toString().split('\n');

if (n[0] % 3 == 0) {
    console.log('짝');
}
else {
    console.log(n[0]);
}