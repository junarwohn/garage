// console.log(0.1 + 0.2)
// Math.sin(3.5);
// var circumference = 2 * Math.PI * 2;
// console.log(circumference)

var avg = function() {
    var sum = 0;
    for (var i = 0, j = arguments.length; i < j; i++) {
        sum += arguments[i];
    }
    return sum / arguments.length;
};

console.log(avg(1,2,3,4,5))