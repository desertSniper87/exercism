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
  }
}
