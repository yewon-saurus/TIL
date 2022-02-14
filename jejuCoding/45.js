let ms = new Date();
let howMuch = ms.getTime();

howMuch /= 1000;
howMuch /= 60;
howMuch /= 60;
howMuch /= 24;
howMuch /= 365;
howMuch += 1970;

console.log(Math.floor(howMuch));