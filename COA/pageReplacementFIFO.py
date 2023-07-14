size = int(input('Enter the size of frame: '))
cache = []
increment = 0
flag = False

#FIFO
while True:
    data = int(input('Enter the element: '))
    
    if len(cache) < size and data not in cache:
        cache.append(data)
    
    elif data not in cache:
        cache.pop((increment))
        cache.insert(increment, data)
        increment = (increment + 1) % size
    
    else:
        flag = True

    print('Cache List: ', cache, '\t\tMiss' if flag == False else 'Hit', '\n')

