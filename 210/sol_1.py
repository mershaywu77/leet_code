class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        # This question is an upgraded version of Q.207, we just output a certain basic_course 
        # sequence
        
        if not prerequisites:
            return list(range(numCourses))[::-1]
        
        pre_posts = collections.defaultdict(set)
        post_pres = collections.defaultdict(set)
        res = []  # saving the basic sequence
        
        for post, pre in prerequisites:
            pre_posts[pre].add(post)
            post_pres[post].add(pre)
            
        basic_courses = [i for i in range(numCourses) if not post_pres[i]]
        
        while basic_courses:
            basic = basic_courses.pop(0)
            res.append(basic)
            
            for post in pre_posts[basic]:
                post_pres[post].remove(basic)
                
                if not post_pres[post]:
                    basic_courses.append(post)
        
        if len(res) == numCourses:
            return res
        else:
            return []
