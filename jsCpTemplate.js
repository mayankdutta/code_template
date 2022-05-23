// https://atcoder.jp/contests/abc061/submissions/1285020
'use strict'

main()

function main (input) {
  readInput()
  .then(parseInput)
  .then(calc)
}

function calc (input) {
  let n = input[0][0]
  let m = input[0][1]
  let edges = new Array(m).fill(0).map(
    (_, i) => ({
      from: input[i + 1][0] - 1,
      to: input[i + 1][1] - 1,
      weight: input[i + 1][2] * -1 // 反転
    })
  )

  // Find loop
  let d = new Array(n).fill(0)
  for (let i = 0; i < n; i++) {
    for (let edge of edges) {
      let shouldUpdate = d[edge.to] > d[edge.from] + edge.weight
      if (shouldUpdate) {
        d[edge.to] = d[edge.from] + edge.weight
        let foundLoop = i === n - 1 && edge.to === n - 1
        if (foundLoop) {
          console.log('inf')
          return
        }
      }
    }
  }

  // Find answer
  d = new Array(n).fill(Infinity)
  d[0] = 0
  for (let i = 0; i < n; i++) {
    for (let edge of edges) {
      let shouldUpdate = d[edge.from] < Infinity && d[edge.to] > d[edge.from] + edge.weight
      if (shouldUpdate) {
        d[edge.to] = d[edge.from] + edge.weight
      }
    }
  }
  console.log(d[n - 1] * -1)
}

function parseInput (inputRaw) {
  let input = inputRaw.split('\n').map(row => row.split(' ').map(Number))
  return input
}

function readInput () {
  return new Promise((resolve) => {
    let inputArr = []
    process.stdin.resume()
    process.stdin.setEncoding('utf8')
    process.stdin.on('data', (chunk) => {
      inputArr.push(chunk)
    })
    process.stdin.on('end', () => {
      let input = inputArr.join('').trim()
      resolve(input)
    })
  })
}
