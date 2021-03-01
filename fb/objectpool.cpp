#include <list>
 
template<typename Object>
class ObjectPool
{
public:
 
    ObjectPool(size_t unSize) : m_size(unSize) {
        for (size_t unIdx = 0; unIdx < m_size; ++ unIdx) {
	           m_oPool.push_back(new Object());
	   }
    }
 
    ~ObjectPool() {
    	typename std::list<Object *>::iterator oIt = m_oPool.begin();
    	while (it != m_oPool.end()) {
    		it = m_oPool.earse(it);
    	}
    	m_size = 0;
    }
 
    Object * GetObject()
    {
        Object * pObj = nullptr;
        if (m_size == 0)
            pObj = new Object();
        else {
            pObj = m_oPool.front();
            m_oPool.pop_front();
            ++m_size;
        }
 
        return pObj;
    }
 
    void ReturnObject(Object * pObj)
    {
        m_oPool.push_back(pObj);
        ++m_size;
    }
 
private:
 
    size_t m_size;
    std::list<object *> m_oPool;
};
