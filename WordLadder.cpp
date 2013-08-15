#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <iterator>
#include <set>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

int ladderLength(string start, string end, unordered_set<string> &dict) {
  queue<string> discover;
  set<string> visited;


  discover.push(start);
  discover.push("");
  visited.insert(start);

  int dist(1);
  string head;
  string tmp;
  while (!discover.empty()) {
    head = discover.front();
    discover.pop();
    if (head == "") {
      if (discover.empty()) break;
      discover.push("");
      ++dist;
      continue;
    }

    for (int i = 0; i != start.length(); ++i) {
      tmp = head;
      for (int j = 'a'; j <= 'z'; ++j) {
	if (j == head[i]) continue;
	tmp[i] = j;
	if (tmp == end) {
	  //return distance[head] + 2;
	  return dist + 1;
	}
	if ((0 != dict.count(tmp)) && (0 == visited.count(tmp))) {
	  discover.push(tmp);
	  visited.insert(tmp);
	  //parents[tmp] = head;
	  //distance[tmp] = distance[head] + 1;
	}
      }
    }
    //visited.insert(head);
    //state[head] = (int)black;
  }
  return 0;
}

int main() {
  // "hot","dot","dog","lot","log"A
  unordered_set<string> wg;
  wg.insert("hot");
  wg.insert("dot");
  wg.insert("dog");
  wg.insert("lot");
  wg.insert("log");
  /*wg.Insert("cat");
  wg.Insert("cap");
  wg.Insert("can");
  wg.Insert("bug");
  wg.Insert("hit");
  wg.Insert("cog");*/
  cout << ladderLength("hit", "cog", wg) << endl;
  //wg.print_graph();
  //wg.BFS("hit");
  return 0;
}
