const input = require('fs').readFileSync('input.txt').toString().trim().split('');

for (var i = 0; i < input.length; i++) {
    if (input[i] == input[i].toUpperCase()) {
        console.log('YES');
    }
    else {
        console.log('NO');
    }
}