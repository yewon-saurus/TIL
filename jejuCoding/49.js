const nums = require('fs').readFileSync('input.txt').toString().trim().split(' ').map((n) => {
    return parseInt(n, 10);
})

let max = 0;
for (let i = 0; i < nums.length; i++) {
    if (max < nums[i]) {
        max = nums[i];
    }
}

console.log(max);