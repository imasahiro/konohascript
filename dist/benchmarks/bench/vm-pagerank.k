/*
 * Calculate PageRank
 * original PHP source http://phpir.com/pagerank-in-php
 */
include "_bench.k";

N=2000;
Map<String,Int[]> links = {
    "1" : [5],
    "2" : [4, 7, 8],
    "3" : [1, 3, 4, 7, 9],
    "4" : [1, 2, 4, 8],
    "5" : [1, 6, 7, 9],
    "6" : [1, 5, 8],
    "8" : [3, 4],
    "9" : [1, 4, 6, 8],
};

Map<String, Float> pagerank_result = {
    "1" : 0.170847568,
    "2" : 0.060138597,
    "3" : 0.095270626,
    "4" : 0.173082449,
    "5" : 0.204222666,
    "6" : 0.086831014,
    "8" : 0.124761846,
    "9" : 0.084845233,
};

float abs(float a) {
    if (a > 0) {
        return a;
    } else {
        return -a;
    }
}

Map<String, Float> calculatePageRank(Map<String, Int[]> linkGraph, float dampingFactor) {
    Map<String, Float> pageRank = {};
    Map<String, Float> tempRank = {};
    int nodeCount = linkGraph.size;

    // initialise the PR as 1/n
    foreach (String node in linkGraph.keys()) {
        pageRank[node] = 1.0/nodeCount;
        tempRank[node] = 0.0;
    }

    float change = 1.0;
    int i = 0;
    while(change > 0.00005 && i < 100) {
        change = 0;
        i++;

        // distribute the PR of each page
        foreach (String node in linkGraph.keys()) {
            Int[] outbound    = linkGraph[node];
            int outboundCount = outbound.size;
            foreach (int link_i in outbound) {
                String link = (String) link_i;
                tempRank[link] += pageRank[node] / outboundCount;
            }
        }

        float total = 0.0;
        // calculate the new PR using the damping factor
        foreach (String node in linkGraph.keys()) {
            Int[] outbound  = linkGraph[node];
            tempRank[node]  = (dampingFactor / nodeCount) + (1-dampingFactor) * tempRank[node];
            change += abs(pageRank[node] - tempRank[node]);
            pageRank[node] = tempRank[node];
            tempRank[node] = 0;
            total += pageRank[node];
        }

        // Normalise the page ranks so it's all a proportion 0-1
        foreach (String node in pageRank.keys()) {
            pageRank[node] = pageRank[node] / total;
        }
    }
    return pageRank;
}
class Bench1 extends BenchMarkTask {
    Bench1() {
        this.name = "PageRank";
    }
    @Override void run() {
        //print "input";
        //foreach (String node in links.keys()) {
        //    print node, links[node];
        //}
        //print "result";
        Map<String, Float> result = {};
        for (int i = 0; i < N; i++) {
            result = calculatePageRank(links, 0.15);
        }
        foreach (String node in result.keys()) {
            if (!result[node].format("%0.9f") == pagerank_result[node].format("%0.9f")) {
                ERR.println("n="+node+": Error!!");
            }
        }
    }
}

void main (String[] args) {
    Benchmark bm = new Benchmark(1);
    bm.addTask new Bench1();
    bm.run();
}
