//
// Created by zhenyus on 11/18/18.
//

#ifndef WEBCACHESIM_UCB_H
#define WEBCACHESIM_UCB_H

#include <unordered_set>
#include <unordered_map>
#include <list>
#include "cache.h"
#include "cache_object.h"
#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>

typedef std::pair<uint64_t, uint64_t> KeyT;

class UCBCache : public Cache
{
public:
    // from id to intervals
    boost::bimap<boost::bimaps::set_of<KeyT>, boost::bimaps::multiset_of<double , std::greater<double >>> mlcache_score;
    std::unordered_map<KeyT, uint64_t> mlcache_plays;

    uint64_t t = 0;

    UCBCache()
            : Cache()
    {
    }
    virtual ~UCBCache()
    {
    }

    virtual bool lookup(SimpleRequest& req);
    virtual void admit(SimpleRequest& req);
    virtual void evict();
    virtual void evict(SimpleRequest& req) {};
};

static Factory<UCBCache> factoryUCB("UCB");


#endif //WEBCACHESIM_UCB_H