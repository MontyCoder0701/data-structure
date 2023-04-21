# Stack Application

## Postfix

Postfix is a notation for writing arithmetic expressions in which the operands appear before their operators. For example, the infix expression `2 + 3` becomes `2 3 +` in postfix notation.

Postfix equations can be solved using stack because the order of operations is determined by the order of operands and operators in the expression.

## Maze

Mazes are a type of puzzle where the goal is to find a path from a starting point to a finishing point through a series of moves. A maze is a 2D array of characters. The characters in the array are either walls or open spaces. The goal is to find a path from the starting point to the finishing point. The starting point is the upper left corner of the maze and the finishing point is the lower right corner of the maze. The path can only move up, down, left, or right. The path cannot move diagonally. The path cannot cross through walls. The path cannot go outside the maze. The path cannot go through the same space twice.

Mazes can be solved using stack because the path can be represented as a stack of coordinates. The starting point is pushed onto the stack. Then, the path is searched for by pushing the coordinates of the adjacent spaces onto the stack. If the path is found, the coordinates of the path are popped off the stack. If the path is not found, the coordinates of the path are popped off the stack and the coordinates of the adjacent spaces are pushed onto the stack. This process is repeated until the path is found or the stack is empty.
