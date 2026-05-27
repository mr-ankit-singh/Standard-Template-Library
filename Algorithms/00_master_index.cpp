// ============================================================
//  STL ALGORITHMS - COMPLETE MASTER NOTES
//  Compile command: g++ -std=c++17 filename.cpp -o output
// ============================================================

/*
  FILE INDEX:
  ===========
  01_nonmodifying_algorithms.cpp  → Read-only algorithms
  02_modifying_algorithms.cpp     → Data modify karne wale
  03_sorting_searching.cpp        → Sort, partition, binary search
  04_set_merge_heap.cpp           → Set ops, merge, heap
  05_minmax_permutation.cpp       → Min/max, permutations
  06_numeric_algorithms.cpp       → Numeric ops (#include <numeric>)

  =============================================
  ALGORITHM QUICK REFERENCE CARD
  =============================================

  NON-MODIFYING (#include <algorithm>):
  ─────────────────────────────────────
  for_each(b,e, fn)           → har element pe fn
  for_each_n(b,n, fn)         → pehle n elements pe fn
  all_of(b,e, pred)           → saare satisfy karte hain?
  any_of(b,e, pred)           → koi ek satisfy karta hai?
  none_of(b,e, pred)          → koi nahi satisfy karta?
  count(b,e, val)             → val kitni baar hai
  count_if(b,e, pred)         → condition wale count
  find(b,e, val)              → iterator to val
  find_if(b,e, pred)          → pehla matching element
  find_if_not(b,e, pred)      → pehla non-matching
  find_end(b,e, sb,se)        → last subsequence occurrence
  find_first_of(b,e, sb,se)   → set mein se pehla
  adjacent_find(b,e)          → consecutive equal pair
  mismatch(b1,e1, b2)         → pehla mismatch pair
  equal(b1,e1, b2)            → do ranges equal hain?
  search(b,e, sb,se)          → subsequence dhundho
  search_n(b,e, n, val)       → n consecutive vals

  MODIFYING (#include <algorithm>):
  ───────────────────────────────────
  copy(b,e, out)              → copy karo
  copy_if(b,e, out, pred)     → condition wale copy
  copy_n(b,n, out)            → n elements copy
  copy_backward(b,e, out_end) → end se copy
  move(b,e, out)              → move karo
  fill(b,e, val)              → val se bharo
  fill_n(b,n, val)            → n elements bharo
  generate(b,e, gen)          → generator se bharo
  generate_n(b,n, gen)        → n elements generate
  transform(b,e, out, fn)     → apply fn, result store
  replace(b,e, old, new)      → old ko new se replace
  replace_if(b,e, pred, new)  → condition wale replace
  remove(b,e, val)            → val "remove" (shift)
  remove_if(b,e, pred)        → condition wale remove
  unique(b,e)                 → consecutive dups remove
  reverse(b,e)                → ulta karo
  rotate(b, new_begin, e)     → rotate karo
  shuffle(b,e, rng)           → randomly shuffle
  swap(a,b)                   → do values swap
  iter_swap(it1, it2)         → iterators se swap
  swap_ranges(b1,e1, b2)      → ranges swap

  SORTING & SEARCHING:
  ─────────────────────
  sort(b,e)                   → O(n log n), unstable
  sort(b,e, cmp)              → custom comparator
  stable_sort(b,e)            → O(n log^2 n), stable
  partial_sort(b,mid,e)       → pehle k sorted
  nth_element(b,nth,e)        → nth correct element
  is_sorted(b,e)              → sorted hai?
  is_sorted_until(b,e)        → kahan tak sorted

  PARTITION:
  ──────────
  partition(b,e, pred)        → true pehle, false baad
  stable_partition(b,e, pred) → order maintain karo
  partition_copy(b,e, t,f, p) → do destinations mein
  is_partitioned(b,e, pred)   → check partition
  partition_point(b,e, pred)  → boundary iterator

  BINARY SEARCH (sorted range required!):
  ────────────────────────────────────────
  binary_search(b,e, val)     → found? (bool)
  lower_bound(b,e, val)       → first >= val
  upper_bound(b,e, val)       → first > val
  equal_range(b,e, val)       → pair{lb, ub}

  SET OPERATIONS (sorted ranges required!):
  ──────────────────────────────────────────
  includes(b1,e1, b2,e2)      → subset check
  set_union(...)              → A ∪ B
  set_intersection(...)       → A ∩ B
  set_difference(...)         → A - B
  set_symmetric_difference    → A △ B

  MERGE:
  ──────
  merge(b1,e1, b2,e2, out)    → do sorted ranges merge
  inplace_merge(b,mid,e)      → same vector ke halves

  HEAP:
  ─────
  make_heap(b,e)              → heap banao
  push_heap(b,e)              → element add (after push_back)
  pop_heap(b,e)               → max remove (before pop_back)
  sort_heap(b,e)              → heap sort (ascending)
  is_heap(b,e)                → check heap property

  MIN/MAX:
  ────────
  min(a,b)                    → chhota
  max(a,b)                    → bada
  minmax(a,b)                 → pair{min,max}
  clamp(v,lo,hi)              → bound karo [C++17]
  min_element(b,e)            → iterator to min
  max_element(b,e)            → iterator to max
  minmax_element(b,e)         → pair{min_it, max_it}

  PERMUTATIONS:
  ─────────────
  next_permutation(b,e)       → agle permutation pe jao
  prev_permutation(b,e)       → pehle permutation pe jao
  is_permutation(b1,e1, b2)   → anagram check

  LEXICOGRAPHIC:
  ──────────────
  lexicographical_compare(...)→ dictionary order compare

  SAMPLING:
  ─────────
  sample(b,e, out, n, rng)    → n random elements [C++17]

  ─────────────────────────────────────────────
  NUMERIC (#include <numeric>):
  ─────────────────────────────────────────────
  accumulate(b,e, init)       → sum (or fold)
  reduce(b,e)                 → parallel accumulate [C++17]
  iota(b,e, start)            → sequence generate
  inner_product(b,e, b2, init)→ dot product
  partial_sum(b,e, out)       → prefix sum
  adjacent_difference(b,e, out)→ consecutive differences
  transform_reduce(...)       → map + reduce [C++17]
  inclusive_scan(b,e, out)    → parallel partial_sum
  exclusive_scan(b,e, out, init)→ shifted scan

  =============================================
  IMPORTANT PATTERNS:
  =============================================

  1. ERASE-REMOVE IDIOM:
     v.erase(remove(v.begin(), v.end(), val), v.end());
     v.erase(remove_if(v.begin(), v.end(), pred), v.end());

  2. SORT + UNIQUE (duplicates hatao):
     sort(v.begin(), v.end());
     v.erase(unique(v.begin(), v.end()), v.end());

  3. ALL PERMUTATIONS:
     sort(v.begin(), v.end());
     do { ... } while(next_permutation(v.begin(), v.end()));

  4. HEAP AS PRIORITY QUEUE:
     make_heap(v.begin(), v.end());
     v.push_back(x); push_heap(v.begin(), v.end()); // insert
     pop_heap(v.begin(), v.end()); v.pop_back();     // extract

  5. BINARY SEARCH WORKFLOW:
     sort(v.begin(), v.end());  // pehle sort
     binary_search(v.begin(), v.end(), x);  // then search

  =============================================
  HEADERS:
  #include <algorithm>  → most algorithms
  #include <numeric>    → accumulate, iota, etc.
  #include <random>     → mt19937 for shuffle/sample
  =============================================
*/

int main() {
    // Yeh file sirf reference card hai
    // Baaki files run karo examples ke liye
    return 0;
}
