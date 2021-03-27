cases = int(input())

for i in range(cases):
    input_lines = int(input())
    words = []
    answer = ""
    start = ""
    mid = ""
    end = ""
    is_impossible = False

    for j in range(input_lines):
        words.append(input())

    for j in range(input_lines):
        temp_start = ""
        temp_end = ""

        for k in range(len(words[j])):
            if(words[j][k] != "*"):
                temp_start += words[j][k]
            else:
                if len(start) < len(temp_start):
                    for l in range (len(start)):
                        if(start[l] != temp_start[len(temp_start)-len(start)+l]):
                            is_impossible = True
                    start = temp_start
                else:
                    for l in range(len(temp_start)):
                        if(temp_start[l] != start[len(start) - len(temp_start) + l]):
                            is_impossible = True
                break
        
        for k in range(len(words[j])-1, -1, -1):
            if(words[j][k] != "*"):
                temp_end += words[j][k]
            else:
                temp_end = temp_end[::-1]

                if len(end) < len(temp_end):

                    for l in range (len(end)):
                        if(end[l] != temp_end[len(temp_end) - len(end) + l]):
                            is_impossible = True

                    end = temp_end
                
                else:
                    for l in range(len(temp_end)):
                        if(temp_end[l] != end[len(end) - len(temp_end) + l]):
                            is_impossible = True

                break

        if is_impossible:
            break

    #temp
    answer = start + end
    if is_impossible:
        print("Case #{}: *".format(i+1))
    else:
        print("Case #{}: {}".format(i+1, answer))
        

                
            

