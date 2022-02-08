const name = require('fs').readFileSync('./jejuCoding/input15.txt').toString().split('\n');

// console.log('안녕하세요. 저는 %s입니다.', name[0]);
console.log(`안녕하세요. 저는 ${name}입니다.`);