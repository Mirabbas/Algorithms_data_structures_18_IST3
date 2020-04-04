let N = Math.floor(Math.random()*10000),
    M = Math.floor(Math.random()*10000);

console.log("N = " + N);
console.log("M = " + M);
const A = [1, N],
      B = [1, M];

for (let i = 0; i < 40; i++) {
    A.push(Number(Math.random()*N).toFixed(0));
    B.push(Number(Math.random()*M).toFixed(0));
}

A.sort((a, b) => a - b );
B.sort((a, b) => a - b );
console.log("A =");
console.log(A);
console.log("B =");
console.log(B);

const C = A.concat(B);
C.sort((a, b) => a - b);
console.log("C =");
console.log(C);
