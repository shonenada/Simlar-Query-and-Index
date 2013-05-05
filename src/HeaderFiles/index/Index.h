#ifndef INDEX_H
#define INDEX_H
#include "../objects/IndexObject.h"
#include "../metric/Metric.h"
#include "../query/Query.h"


#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>

/** @defgroup INDEX SQAI:INDEX
*  @author Fuli Lei
*  @version 2012-12-09
*  @{
*/

/**This abstract class is the primary interface for distance-based index. 
* users can build a database index or read a pre-build index from a file,
* then do the search.
*/
class CIndex
{
public:
	
	/**this pure virtual funciton need to be implemented by the same function in its derived class,
		then users can use it to create a index

		@param[in] objectList this is vector contains all the objects of a index structure built later
	*/
	virtual void bulkLoad(vector<CIndexObject*> &objectList)=0;

	/**this is a pure virtual function 
	    users can use it to search out what they want after this
		pure virtual function is implemented in the derived class

		@para[in] q this object package some information used to do the search
		@return this function will return a vector consists of all objects generated by this function. 
	*/
	virtual vector<CIndexObject*> search(CQuery* q)=0;

	/**this is a pure virtual function 
		users can get all the data objects residing in the index structure use the 
		same function, which implementes this pure virtual function, in the derived class of this abstract base class
	*/
	virtual vector<CIndexObject*> getAllDataPoints()=0;
	
	/**Users can get a metric object through this function implemented in the derived class of 
		this abstract base class 
	*/
	virtual CMetric* getMetric()=0;

	/**when this pure function is implemented in the derived class,users can get the number of object residing in 
	    the index structure built before
	*/
	virtual int size()=0;

	/**Write a index previously built to a file stored in outside memory. This function must be implemented in anvance before being called
		@para out a class boost::serialization::text_oarchive object, which will be used to out put the index built before. 
	*/
	virtual void write(text_oarchive &out)=0;
	/**Read a index from a file stored in outside memory. This function must be implemented in anvance before being called
		@para in a class boost::serialization::text_iarchive object, which will be used to read a index stored in the file resides in the outside memory.
	*/
	virtual void read(text_iarchive &in)=0;


private:
	friend class boost::serialization::access;
	/** Function for object serialization */
	template<class Archive>
	void serialize(Archive & ar,const unsigned int version)
	{

	}
};
/**@}*/
#endif