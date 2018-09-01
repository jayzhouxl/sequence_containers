# sequence_containers
测试vector,deque,list容器的插入，删除，查找的性能
#从测试结果来看
插入
               vector                  list                          deque
10000          484microsecond        2932microsecond               816microsecond
100000         4515microsecond       40833microsecond              1656microsecond
1000000        47254microsecond     1s -717663microsecond          55265microsecond
针对插入来说的，无论是大数量还是小数据量性能 vector > deque > list


查找
               vector                  list                          deque
10000          73microsecond        116microsecond               94microsecond
100000        804microsecond       1772microsecond              470microsecond
1000000        8806microsecond     11615microsecond          11447microsecond
针对查找来说，无论是大数量还是小数据量性能 vector > deque > list

删除
               vector                  list                          deque
10000          6microsecond        17microsecond               159microsecond
100000        27microsecond       27microsecond              834microsecond
1000000        541microsecond     40microsecond          18895microsecond
针对删除来说，无论是小数据量性能 vector > list > deque 大数量 list > vector > deque
