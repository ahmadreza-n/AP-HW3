SELECT first_name
FROM user_
WHERE phone = '09120000001';

UPDATE user_ 
SET email = 'm.gmail@apstudent201' 
WHERE phone = '09120000001';

SELECT channel_id
FROM channelMembership
WHERE user_id IN(SELECT telegram_id
FROM user_
WHERE phone = '09120000001');

SELECT COUNT(*)
FROM channelMembership
WHERE channel_id = '2019_ap_aut';

SELECT email
FROM user_
WHERE phone LIKE '0935%';

SELECT phone
FROM user_
WHERE telegram_id IN (
    SELECT blocked_user_id
FROM blockUser
WHERE blocker_user_id = ( SELECT telegram_id
From user_
WHERE phone = '09120000001')
);

