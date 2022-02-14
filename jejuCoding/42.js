const input = require('fs').readFileSync('input.txt').toString().trim().split(' ');
const a = input[0];
const b = input[1];

function week(a, b) {
    const day = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT'];

    const x = new Date('2020-'+a+'-'+b);
    return day[x.getDay()];
}

console.log(week(a, b));