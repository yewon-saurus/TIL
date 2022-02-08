const n = require('fs').readFileSync('./jejuCoding/input13.txt').toString().split('');

const planet = ['수성', '금성', '지구', '화성', '목성', '토성', '천왕성', '해왕성'];
console.log(planet[(n[0] - 1)]);