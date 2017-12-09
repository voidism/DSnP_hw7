/****************************************************************************
  FileName     [ myMinHeap.h ]
  PackageName  [ util ]
  Synopsis     [ Define MinHeap ADT ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2014-present LaDs(III), GIEE, NTU, Taiwan ]
****************************************************************************/

#ifndef MY_MIN_HEAP_H
#define MY_MIN_HEAP_H

#include <algorithm>
#include <vector>

#define swapData(A, B) Data temp = A; A = B; B = temp;

template <class Data>
class MinHeap
{
public:
  MinHeap(size_t s = 0)
  {
    if (s != 0)
      _data.reserve(s);
  }
  ~MinHeap() {}

  void clear() { _data.clear(); }

  // For the following member functions,
  // We don't respond for the case vector "_data" is empty!
  const Data &operator[](size_t i) const { return _data[i]; }
  Data &operator[](size_t i) { return _data[i]; }

  size_t size() const { return _data.size(); }

  // TODO
  const Data &min() const {/* if (!(_data.empty()))  */return _data.at(0); }
  void insert(const Data &d)
  {
    unsigned idx = _data.size();
    _data.push_back(d);
    if(idx == 0) return;
    while (idx > 0)
    {
      if (_data.at(idx) < _data.at((idx - 1) / 2))
      {
        swapData(_data.at(idx), _data.at((idx - 1) / 2));
        idx = (idx - 1) / 2;
      }
      else
        break;
      }
  }
  void delMin()
  {
    delData(0);
  }
  void delData(size_t i) {
    if(_data.empty()) return;
    if(i>=_data.size()) return;
    _data.at(i) = _data.at(_data.size() - 1);
    _data.pop_back();
    while(i*2+1<_data.size()){
      unsigned j = i * 2 + 1;
      if((j+1)<_data.size()) {j = (_data.at(j + 1) < _data.at(j)) ? j + 1 : j;}
      if(_data.at(j)<_data.at(i)) {swapData(_data.at(j), _data.at(i));}
      else break;
      i = j;
    }
    while (((i - 1) / 2) > 0){
      if (_data.at(i) < _data.at((i - 1) / 2)){
        swapData(_data.at(i), _data.at((i - 1) / 2));
        i = (i - 1) / 2;
      }
      else break;
    }
  }

private:
  // DO NOT add or change data members
  vector<Data> _data;
};

#endif // MY_MIN_HEAP_H
