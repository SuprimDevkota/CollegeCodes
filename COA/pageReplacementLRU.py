size = int(input('Enter the size of frame: '))
cache = []
lruList = []
flag = False

#LRU
while True:
    data = int(input('Enter the element: '))
    
    if len(cache) < size and data not in cache:
        cache.append(data)
        lruList.append(data)
    
    elif data not in cache:
        index = cache.index(lruList[0])
        cache.pop(index)
        cache.insert(index, data)
        lruList.pop(0)
        lruList.append(data)
    
    else:
        lruList.remove(data)
        lruList.append(data)
        flag = True

    print('Cache List: ', cache, ' Least Recently used List: ', lruList, '\t\tMiss' if flag == False else 'Hit', '\n')

