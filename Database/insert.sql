INSERT INTO user_
VALUES(0 , 'ahmad', '09120000001',
                'ahmad@gmail.com', 'password',
                'ahmad', 'nazari', 1234, 'null', NOW(), NOW());

INSERT INTO user_
VALUES(1 , 'reza', '09120000000',
                'reza@gmail.com', MD5('password'),
                'reza', 'hasani', 1234, 'null', NOW(), NOW());

INSERT INTO user_
VALUES(2 , 'mamad', '09350000001',
                'mamad@gmail.com', 'password',
                'mamad', 'qoli', 1234, 'null', NOW(), NOW());

INSERT INTO user_
VALUES(3 , 'mohsen', '09350000002',
                'apstudent2019@gmail.com', 'password',
                'mohsen', 'sajedi', 1234, 'null', NOW(), NOW());

INSERT INTO channel
VALUES(0, 'discovery', 'discovery', 'discovery',
                'reza', NOW(), NOW());

INSERT INTO channelMembership
VALUES('ahmad', 'discovery', NOW());

INSERT INTO channelMembership
VALUES('reza', 'discovery', NOW());

INSERT INTO channelMembership
VALUES('mohsen', 'discovery', NOW());

INSERT INTO channel
VALUES(1, '2019_ap_aut', '2019_ap_aut', '2019_ap_aut',
                'reza', NOW(), NOW());

INSERT INTO channelMembership
VALUES('ahmad', '2019_ap_aut', NOW());

INSERT INTO blockUser
VALUES('ahmad', 'mamad', NOW());