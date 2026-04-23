const boardElement = document.getElementById("board");
const sizeInput = document.getElementById("sizeInput");
const solveBtn = document.getElementById("solveBtn");
const resetBtn = document.getElementById("resetBtn");
const prevBtn = document.getElementById("prevBtn");
const nextBtn = document.getElementById("nextBtn");
const message = document.getElementById("message");
const solutionInfo = document.getElementById("solutionInfo");

let size = 8;
let board = [];
let solutions = [];
let currentSolution = 0;

function createBoard(n) {
  return Array.from({ length: n }, () => Array(n).fill(0));
}

function drawBoard() {
  boardElement.innerHTML = "";
  boardElement.style.gridTemplateColumns = `repeat(${size}, 1fr)`;
  boardElement.style.gridTemplateRows = `repeat(${size}, 1fr)`;

  for (let row = 0; row < size; row++) {
    for (let col = 0; col < size; col++) {
      const cell = document.createElement("div");
      cell.className = `cell ${(row + col) % 2 === 0 ? "white" : "black"}`;

      if (board[row][col] === 1) {
        cell.innerHTML = '<span class="queen">♛</span>';
      }

      boardElement.appendChild(cell);
    }
  }

  updateSolutionInfo();
}

function isSafe(row, col) {
  for (let i = 0; i < row; i++) {
    if (board[i][col] === 1) {
      return false;
    }
  }

  for (let i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] === 1) {
      return false;
    }
  }

  for (let i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++) {
    if (board[i][j] === 1) {
      return false;
    }
  }

  return true;
}

function saveSolution() {
  solutions.push(board.map((row) => [...row]));
}

function solveNQueen(row) {
  if (row === size) {
    saveSolution();
    return;
  }

  for (let col = 0; col < size; col++) {
    if (isSafe(row, col)) {
      board[row][col] = 1;
      solveNQueen(row + 1);
      board[row][col] = 0;
    }
  }
}

function showSolution(index) {
  if (solutions.length === 0) {
    return;
  }

  currentSolution = (index + solutions.length) % solutions.length;
  board = solutions[currentSolution].map((row) => [...row]);
  drawBoard();
}

function updateSolutionInfo() {
  if (solutions.length === 0) {
    solutionInfo.textContent = "Solution: -";
    prevBtn.disabled = true;
    nextBtn.disabled = true;
    return;
  }

  solutionInfo.textContent = `Solution: ${currentSolution + 1} / ${solutions.length}`;
  prevBtn.disabled = solutions.length < 2;
  nextBtn.disabled = solutions.length < 2;
}

function solve() {
  size = Number(sizeInput.value);

  if (size < 4 || size > 12) {
    message.textContent = "Please enter a value between 4 and 12.";
    return;
  }

  board = createBoard(size);
  solutions = [];
  currentSolution = 0;

  solveNQueen(0);

  if (solutions.length === 0) {
    message.textContent = "No solution found.";
    drawBoard();
    return;
  }

  message.textContent = `Total solutions found: ${solutions.length}`;
  showSolution(0);
}

function reset() {
  size = Number(sizeInput.value) || 8;
  board = createBoard(size);
  solutions = [];
  currentSolution = 0;
  message.textContent = "Ready";
  drawBoard();
}

solveBtn.addEventListener("click", solve);
resetBtn.addEventListener("click", reset);
prevBtn.addEventListener("click", () => showSolution(currentSolution - 1));
nextBtn.addEventListener("click", () => showSolution(currentSolution + 1));
sizeInput.addEventListener("change", reset);

reset();
