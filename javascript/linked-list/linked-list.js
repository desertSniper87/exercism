//
// This is only a SKELETON file for the 'Linked List' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export class LinkedList {
  constructor() {
    this.head = null;
  }

  push(el) {
    let n = new Node(el, null);

    if (this.head == null)
      this.head = n;
    else {
      let cur = this.data;
      while (cur.next != null){
        cur = cur.next;
      }
      cur.next = n;
    }
  }

  pop() {
    return this.data.val;
  }

  shift() {
    throw new Error("Remove this statement and implement this function");
  }

  unshift() {
    throw new Error("Remove this statement and implement this function");
  }

  delete() {
    throw new Error("Remove this statement and implement this function");
  }

  count() {
    throw new Error("Remove this statement and implement this function");
  }
}

class Node {
  constructor(val, next) {
    this.val = val;
    this.next = next;
  }

  get() {
    return this.val;
  }
}
