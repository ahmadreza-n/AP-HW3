CREATE TABLE user_
(
    id SERIAL,
    telegram_id VARCHAR(40) PRIMARY KEY,
    phone VARCHAR(13) NOT NULL,
    email VARCHAR(40) NOT NULL,
    password_ VARCHAR(40) NOT NULL,
    first_name VARCHAR(40) NOT NULL,
    last_name VARCHAR(40) NOT NULL,
    verification_code INT NOT NULL,
    profile_picture_url TEXT ,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

CREATE TABLE blockUser
(
    blocker_user_id VARCHAR(40),
    blocked_user_id VARCHAR(40),
    created_at TIMESTAMP NOT NULL,
    FOREIGN KEY (blocker_user_id) REFERENCES user_,
    FOREIGN KEY (blocked_user_id) REFERENCES user_
);

CREATE TABLE message_
(
    id SERIAL PRIMARY KEY,
    sender_id VARCHAR(40) NOT NULL,
    receiver_id VARCHAR(40) NOT NULL,
    message_type VARCHAR(6) NOT NULL,
    message_text TEXT NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    FOREIGN KEY (receiver_id) REFERENCES user_,
    FOREIGN KEY (sender_id) REFERENCES user_,
    CHECK (message_type IN('text', 'voice', 'image', 'video'))
);

CREATE TABLE channel
(
    id SERIAL,
    telegram_id VARCHAR(40) PRIMARY KEY NOT NULL,
    title VARCHAR(40) NOT NULL,
    info TEXT,
    creator_id VARCHAR(40) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    FOREIGN KEY (creator_id) REFERENCES user_
);

CREATE TABLE group_
(
    id SERIAL PRIMARY KEY,
    creator_id VARCHAR(40) NOT NULL,
    title VARCHAR(40) NOT NULL,
    join_url TEXT,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    FOREIGN KEY (creator_id) REFERENCES user_
);

CREATE TABLE groupMessage
(
    id SERIAL PRIMARY KEY,
    group_id VARCHAR(40) NOT NULL,
    sender_id VARCHAR(40) NOT NULL,
    message_type VARCHAR(6) NOT NULL,
    message_text TEXT,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    FOREIGN KEY (sender_id) REFERENCES user_,
    CHECK (message_type IN('text', 'voice', 'image', 'video'))
);

CREATE TABLE channelMessage
(
    id SERIAL PRIMARY KEY,
    channel_id VARCHAR(40) NOT NULL,
    message_type VARCHAR(6) NOT NULL,
    message_text TEXT,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,
    CHECK (message_type IN('text', 'voice', 'image', 'video'))
);

CREATE TABLE messageAttachment
(
    message_id SERIAL,
    attachment_url TEXT,
    attachment_thumb_url TEXT,
    FOREIGN KEY (message_id) REFERENCES message_
);


CREATE TABLE groupMessageAttachment
(
    message_id SERIAL,
    attachment_url TEXT,
    attachment_thumb_url TEXT,
    FOREIGN KEY (message_id) REFERENCES groupMessage
);

CREATE TABLE channelMessageAttachment
(
    message_id SERIAL,
    attachment_url TEXT,
    attachment_thumb_url TEXT,
    FOREIGN KEY (message_id) REFERENCES channelMessage
);

CREATE TABLE channelMembership
(
    user_id VARCHAR(40) NOT NULL,
    channel_id VARCHAR(40),
    created_at TIMESTAMP NOT NULL,
    FOREIGN KEY (channel_id) REFERENCES channel,
    FOREIGN KEY (user_id) REFERENCES user_
);

CREATE TABLE groupMembership
(
    group_id SERIAL,
    user_id VARCHAR(40) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    FOREIGN KEY (group_id) REFERENCES group_,
    FOREIGN KEY (user_id) REFERENCES user_
);