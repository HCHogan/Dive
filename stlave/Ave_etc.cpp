#ifndef __ETC_FUNC
#define __ETC_FUNC

#include "iterator_traits"

template<class inputiterator>
inline iterator_traits<inputiterator>::difference_type __distance(inputiterator first, inputiterator last, input_iterator_tag)
{
    iterator_traits<inputiterator>::difference_type n=0;
    while(first!=last)
    {
        ++first;
        ++n;
    }
    return n;
}

template<class randomaccessiterator>
inline iterator_traits<randomaccessiterator>::difference_type __distance(randomaccessiterator first, randomaccessiterator last, input_iterator_tag)
{
  //return last-first;
}

template<class inputiterator>
inline iterator_traits<inputiterator>::difference_type distance(inputiterator first, inputiterator last)
{
    typedef typename iterator_traits<inputiterator>::iterator_category category;
    return __distance(first, last, category());
}
//the compiler decide which overloading by the **iterator_tag**


template<class inputiterator, class distance>
inline void __advance(inputiterator& i, distance n, input_iterator_tag)
{
    while(n--) ++i;
}

template<class bidirectionaliterator, class distance>
inline void __advance(bidirectionaliterator i, distacne n, bidirecitonal_iterator_tag)
{
    if(n>=0)
        while(n--) ++i;
    if(n<0)
        while(n++) --i;
}

template<class randomaccessiterator, class distance>
inline void __advance(randomaccessiterator i, distance n, random_access_iterator_tag)
{
    i+=n;
}

template<class inputiterator, class distance>
inline void advance(inputiterator& i, distance n)
{
    __advance(i,n,iterator_category(i));
}
//this function makes the iterator step forward for n times

template<class Iterator>
inline typename iterator_traits<Iterator>::iterator_category iterator_category(const Iterator&)
{
    typedef typename iterator_traits<Iterator>::iterator_category category;
    return category();
}
//help to find the category of a iterator





#endif
