/*alarm的id打散。一个alarm会变成两个item：(start_time, alarm_id, priority, is_start=true), 
(end_time, alarm_id, priority, is_start=false)
把所有的2N个items排序。按照第一个field time从小到大排序。
依次访问排序后的每个item
如果is_start=true，那么 check priority 是否在某个集合中，如果不在的话就create一个entry 给这个priority，将alarm_id添加到该priority的一个list里，表示当前是该priority的alarms有哪些。entry包括两个部分，一个是priority，作为key，第二个是一个list，表示有哪些alarms，作为value。
如果is_start=false，那么 找到集合中priority对应的entry，然后把alarm_id从里面删除，如果entry里的list空了，就在集合中删除这条entry。
上面的操作完成后，检查目前集合中priority最高的entry，把这个entry里的alarms都标记为成为过最高优先级的。
最后再check所有的alarm，看看哪些没有被标记过。
这中间有一个优化需要做的是，需要把list分为已经标记过成为最高优先级的，和没有标记过成为最高优先级的。否则反复标记同一个alarm成为过最高优先级会耗费时间复杂度。
 这个list，本身因为需要支持插入和删除的话，那么其实实际上应该是两个hashset。
整体的时间复杂度是(NlogN + NlogP)，N为alarms的个数，P为Priority的个数，NlogN是排序的复杂度，NlogP是后面统计处理的时候的复杂度。
至于这个集合既需要做key-value的查询，又需要找最大值，那么自然是HashHeap。
*/ 
  vector<pair<int, int>> removealarms(vector<Alarm>& alarms) {
        vector<pair<int, int>> weight;
        for (auto &b : alarms) {
            wight.push_back({b.start, -b.weight});
            wight.push_back({b.end, b.weight});
        }
        sort(wight.begin(), wight.end());
        multiset<int> heap;
        unordered_set<int> sets;
        heap.insert(0);
        vector<pair<int, int>> res;
        int pre = 0, cur = 0;
        for (int i=0;i<wight.size();i++) {
            if (weight[i].second < 0) {
                heap.insert(-weight[i].second);
            } else {
                heap.erase(heap.find(wight[i].second));
            }   
            cur = *heap.rbegin();  // find the maxium
            if (cur != pre) {
                set.insert(cur);
                pre = cur;
            }
        }
        for (int i=0;i<alarm.size();i++){
        	if !sets.count(alarm[i].wight)
        		alarms.erase(alarms.begin()+i);
        }
        return res;
 }

