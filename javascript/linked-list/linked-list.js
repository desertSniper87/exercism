export class LinkedList {
  constructor() {
    this.head = null;
  }

  push(el) {
    let n = new Node(el, null);

    if (this.head === null)
      this.head = n;
    else {
      let cur = this.head;
      while (cur.next != null) {
        cur = cur.next;
      }
      cur.next = n;
    }
  }

  pop() {
    let cur = this.head;
    let prev = null;
    while (cur.next != null) {
      prev = cur;
      cur = cur.next;
    }
    if (prev != null)
      prev.next = null;
    else
      this.head = null;

    return cur.val;
  }

  shift() {
    let cur = this.head;
    this.head = cur.next;
    return cur.val;
  }

  unshift(el) {
    let n = new Node(el, this.head);
    this.head = n;
  }

  delete(el) {
    let cur = this.head;
    let prev = null;
    if (cur.val === el)
      if (this.head.next === null)
        this.head = null;
      else 
        this.head = this.head.next;

    while (cur.next != null) {
      prev = cur;
      cur = cur.next;

      if (cur.val === el) {
        prev.next = cur.next;
        break
      }
    }
  }

  count() {
    let cur = this.head; 
    let cnt = 1;

    if (cur === null)
      return 0;
    else if (cur.next === null)
      return 1;

    while (cur.next!=null) {
      cur = cur.next;
      cnt++;
    }
    return cnt;

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
