import collections
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        # A course can be taken ifdose NOT HAVE ANY PREREQUISITE(S), such course is namely basic             
        # course. Since all nodes are provided by the prerequisites pairs, thre is no sole nodes
        # that without any post course
        
        # The idea is like we gradually clear the dependency(ies) of the node from the graph to see
        # how many of nodes without dependency (becomes basic course at the moment)
        
        # There is a need to create two mappings: 1. pre_posts mappnig  2. post_pres mapping
        # pre_posts mappnig is used to iterate its values(posts) for each basic, find such values in         
        # post_pres mapping and remove the basic to see when it becomes basic
        
        # we also count basic in the above process, finally compare n with numCourses
        
        if len(prerequisites) == 0:
            return True
        
        n = 0  # count the total number of basic courses
        pre_posts = collections.defaultdict(set)  # pre_posts mappnig
        post_pres = collections.defaultdict(set)  # post_pres mapping
        
        for post, pre in  prerequisites:
            pre_posts[pre].add(post)  # 供后面查字典用，这个字典不参与后面修改
            post_pres[post].add(pre)
            
        basic_courses = [i for i in range(numCourses) if not post_pres[i]]  # courses without pre-course
        while basic_courses:
            basic = basic_courses.pop(0)
            n += 1
            for item in pre_posts[basic]:
                post_pres[item].remove(basic)
                
                if not post_pres[item]:
                    basic_courses.append(item)
                    
        return n==numCourses
