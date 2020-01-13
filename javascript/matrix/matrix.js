const transpose = matrix => {
  let result = new Array();

  for (let i = 0; i < matrix[0].length; i++) {
    result[i] = new Array(matrix[0].length -1 ).fill();

    for (let j = 0; j < matrix.length; j++) {
      result[i][j] = matrix[j][i]; 
    }
  }

  return result;
}

export class Matrix {
  constructor(data) {
    const split_data = data.split("\n");
    this.data = split_data.map(x => x.split(" ")
                                     .map(y => Number(y)));
  }

  get rows() {
    return this.data;
  }

  get columns() {
    return transpose(this.data);
  }
}
