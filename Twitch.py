def solution(min_cheermote_amount, valid_cheermotes, messages):
    total_cheers = {}
    for cheermote in valid_cheermotes:
        total_cheers[cheermote] = 0
        
    messages_arr = messages.split(',')
    for message in messages_arr:
        msg_total_cheers = {}
        valid = True
        total_bits = 0
        
        for index in range(0, len(message)):
            for cheermote in valid_cheermotes:
                # check if prefix is a cheermote and after it is a numeric digit
                if message[index:].startswith(cheermote) and message[index+len(cheermote)].isdigit():
                    # extract the numeric value of the bits from the message
                    bits = 0
                    digit_index = index + len(cheermote)
                    while digit_index < len(message) and message[digit_index].isdigit():
                        bits = bits*10 + int(message[digit_index])
                        digit_index += 1
                    
                    # total bits cannot exceed 100,000
                    total_bits += bits
                    if total_bits > 100000:
                        valid = False
                        
                    # check if bits is valid
                    if bits >= min_cheermote_amount and bits <= 10000:
                        if cheermote not in msg_total_cheers:
                            msg_total_cheers[cheermote] = bits
                        else:
                            msg_total_cheers[cheermote] += bits
                    else:
                        valid = False
                        
                    # skip the index past this cheermote
                    index = digit_index
                        
        # only add the bits in this message if it is valid
        if valid:
            for cheermote, cheers in msg_total_cheers.items():
                total_cheers[cheermote] += cheers
            
    # remove cheermotes that have 0 cheers
    for cheermote in valid_cheermotes:
        if total_cheers[cheermote] == 0:
            total_cheers.pop(cheermote, None)
    
    # check if there are no cheers (empty dict)
    if not total_cheers:
        return ["NO_CHEERS"]
    else:
        # sort cheermotes descending by total bits
        sorted_cheers = [cm + str(b) for cm, b in sorted(total_cheers.items(), key=lambda item: -item[1])]
        return sorted_cheers     

print(solution(5, ['cheer', 'party', 'pogchamp'], 'cheer1 cheer10 pogchamp1 wow!, cheer5 cheer10 this is amazing, party50 party50 lets have a party!'))
