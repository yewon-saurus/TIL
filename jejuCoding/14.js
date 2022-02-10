const n = require("fs").readFileSync('input.txt').toString().split('\n');

if (n[0] % 3 == 0) {
    console.log('짝');
}
else {
    console.log(n[0]);
}