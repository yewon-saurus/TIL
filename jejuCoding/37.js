const array = require('fs').readFileSync('input.txt').toString().trim().split(' ');

let result = {};
let winner = "";

for(let index in array){
  let val = array[index];
  result[val] = (result[val] === undefined) ? 1 : (result[val] + 1);
}

winner = Object.keys(result).reduce((a, b) => {
  return (result[a] > result[b]) ? a : b
});

console.log(`${winner}(이)가 총 ${result[winner]}표로 반장이 되었습니다.`);