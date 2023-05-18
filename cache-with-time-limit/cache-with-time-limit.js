class TimeLimitedCache {
  cache = {};
  queue = new MinPriorityQueue();
  size = 0;

  handleExpiredData() {
    const now = Date.now();
    while (this.queue.size() > 0 && this.queue.front().priority < now) {
      const entry = this.queue.dequeue().element;
      if (!entry.overwritten) {
        delete this.cache[entry.key];
        this.size -= 1;
      }
    }
  };

  set(key, value, duration) {
    this.handleExpiredData();
    const hasVal = key in this.cache
    if (hasVal) {
      this.cache[key].overwritten = true
    } else {
      this.size += 1;
    }
    const expiration = Date.now() + duration;
    const entry = { key, value, expiration, overwritten: false }
    this.cache[key] = entry
    this.queue.enqueue(entry, expiration);
    return hasVal;
  }

  get(key) {
    this.handleExpiredData();
    if (this.cache[key] === undefined) return -1;
    return this.cache[key].value;
  }

  count() {
    this.handleExpiredData();
    return this.size;
  }
};
/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */