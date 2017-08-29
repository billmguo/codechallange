def getExistedNode(path):
    node = {'dir':{},'files':{}}
    for dir in filter(len, path.split('/')):
        if dir in node['dirs']: 
            node = node['dirs'][dir]
        else:
             return node, 'file'
    return node, 'dir'

a, b = getExistedNode("/local/mnt/workspace")
print a
print b
