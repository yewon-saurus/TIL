const korPl = ['수성', '금성', '지구', '화성', '목성', '토성', '천왕성', '해왕성'];
const engPl = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune'];

const input = require('fs').readFileSync('input.txt').toString().split('\n');

for (var i = 0; i < 8; i++) {
    if (input[0] == korPl[i]) {
        console.log(engPl[i]);
    }
}