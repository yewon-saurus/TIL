const n = require('fs').readFileSync('input.txt').toString().trim().split('\n');

for (let i = 0; i*i < n; i++) {
    if (n  % i == 0) {
        console.log(`${n}은 소수가 아닙니다.`);
        break;
    }
    else {
        console.log(`${n}은 소수입니다.`);
        break;
    }
}