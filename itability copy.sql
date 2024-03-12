

-- 게시글 테이블
CREATE TABLE board (
	board_id	INT AUTO_INCREMENT NOT NULL,
	board_title	VARCHAR(100) NOT NULL,
	board_content	VARCHAR(1000) NOT NULL,
	write_date	VARCHAR(13) NOT NULL,
	hits	INT NOT NULL DEFAULT 0,
	report_count	INT NOT NULL DEFAULT 0,
	is_active	BOOLEAN NOT NULL DEFAULT TRUE,
	member_id	BIGINT NOT NULL,
	img_id	VARCHAR(255),
	PRIMARY KEY (board_id)
);

-- 댓글 테이블
CREATE TABLE comment (
	cmt_id	INT AUTO_INCREMENT NOT NULL,
	write_date	VARCHAR(13) NOT NULL,
	report_count	INT NOT NULL DEFAULT 0,
	board_id	INT NOT NULL,
	member_id	BIGINT NOT NULL,
	PRIMARY KEY (cmt_id),
	FOREIGN KEY (board_id) REFERENCES board (board_id)
);

-- 신고 테이블
CREATE TABLE report (
	report_id	INT AUTO_INCREMENT NOT NULL,
	report_date	VARCHAR(255) NOT NULL,
	board_id	INT,
	member_id	BIGINT NOT NULL,
	report_category_id	VARCHAR(255) NOT NULL,
	cmt_id	INT,
	recruit_id	INT,
	PRIMARY KEY (report_id),
	FOREIGN KEY (board_id) REFERENCES board (board_id),
	FOREIGN KEY (cmt_id) REFERENCES comment (cmt_id)
);

-- 블랙리스트 테이블
CREATE TABLE blacklist (
	blacklist_id	INT AUTO_INCREMENT NOT NULL,
	blacklist_date	VARCHAR(255) NOT NULL,
	member_id	BIGINT NOT NULL,
	PRIMARY KEY (blacklist_id)
);

-- 구인 테이블
CREATE TABLE recruit (
	recruit_id	INT AUTO_INCREMENT NOT NULL,
	recruit_type	ENUM("O", "S") NOT NULL COMMENT "O: 외주, S: 스터디",
	recruit_title	VARCHAR(100) NOT NULL,
	recruit_content	VARCHAR(1000) NOT NULL,
	recruit_expdate	VARCHAR(13) NOT NULL,
	recruit_mb_cnt	INT NOT NULL,
	recruit_category_id	INT NOT NULL,
	member_id	BIGINT NOT NULL,
	PRIMARY KEY (recruit_id)
);

-- 팔로우 테이블
CREATE TABLE follow (
	follow_id	INT AUTO_INCREMENT NOT NULL,
	member_id_following	INT NOT NULL,
	member_id_followed	INT NOT NULL,
	PRIMARY KEY (follow_id)
);

-- 좋아요 테이블
CREATE TABLE board_like (
	like_id	INT AUTO_INCREMENT NOT NULL,
	board_id	INT NOT NULL,
	member_id	BIGINT NOT NULL,
	PRIMARY KEY (like_id),
	FOREIGN KEY (board_id) REFERENCES board (board_id)
);



-- 회원 정보 테이블
CREATE TABLE member_info (
                           member_id BIGINT NOT NULL,
                           img_id VARCHAR(255) ,
                           provider ENUM("KAKAO", "NAVER", "GOOGLE") NOT NULL,
                           name VARCHAR(255),
                           birth_year VARCHAR(4),
                           birth_day VARCHAR(10),
                           email VARCHAR(255) NOT NULL,
                           phone VARCHAR(20),
                           gender VARCHAR(10),
                           is_blacklisted	BOOLEAN NOT NULL DEFAULT FALSE,
                           blacklist_count	INT NOT NULL DEFAULT 0,
                           report_count	INT NOT NULL DEFAULT 0,
                           	PRIMARY KEY (member_id)
);



-- 회원 프로필 테이블
CREATE TABLE member_profile (
	member_id	BIGINT NOT NULL,
	nickname	VARCHAR(30) NOT NULL,
	img_id	VARCHAR(255) NOT NULL DEFAULT "DEFAULT_IMG",
	degree_id	INT NOT NULL,
	FOREIGN KEY (member_id) REFERENCES member_info (member_id),
	PRIMARY KEY (member_id)
);

-- 학위 정보 테이블
CREATE TABLE degree (
	degree_id	INT AUTO_INCREMENT NOT NULL,
	final_edu_name	VARCHAR(100),
	enroll_date	VARCHAR(13),
	graduate_date	VARCHAR(13),
	major	VARCHAR(50),
	register_status	BOOLEAN,
	PRIMARY KEY (degree_id)
);

-- 기술 스킬 테이블
CREATE TABLE skill (
	skill_id	INT AUTO_INCREMENT NOT NULL,
	skill_name	VARCHAR(30) NOT NULL,
	PRIMARY KEY (skill_id)
);

-- 경력 정보 테이블
CREATE TABLE career (
	career_id	INT AUTO_INCREMENT NOT NULL,
	company_name	VARCHAR(100) NOT NULL,
	start_date	VARCHAR(13) NOT NULL,
	end_date	VARCHAR(13),
	role	VARCHAR(60) NOT NULL,
	assigned_task	VARCHAR(255) NOT NULL,
	is_current_job	BOOLEAN NOT NULL,
	member_id	BIGINT NOT NULL,
	PRIMARY KEY (career_id),
	FOREIGN KEY (member_id) REFERENCES member_info (member_id)
);

-- 이미지 테이블
CREATE TABLE image (
	img_id	VARCHAR(255) NOT NULL,
	img_use	ENUM("profile", "post") NOT NULL COMMENT "프로필, 게시글",
	ext	VARCHAR(5) NOT NULL COMMENT "png, jpg, jpeg",
	path	VARCHAR(255) NOT NULL,
	PRIMARY KEY (img_id)
);

-- 신고 카테고리 테이블
CREATE TABLE report_category (
	report_category_id	VARCHAR(255) NOT NULL,
	report_name	VARCHAR(255) NOT NULL,
	PRIMARY KEY (report_category_id)
);

-- 구인 카테고리 테이블
CREATE TABLE recruit_category (
	recruit_category_id	INT AUTO_INCREMENT NOT NULL,
	recruit_name	VARCHAR(30) NOT NULL,
	PRIMARY KEY (recruit_category_id)
);

-- 회원-기술 매핑 테이블
CREATE TABLE member_skill (
	member_id	BIGINT NOT NULL,
	skill_id	INT NOT NULL,
	PRIMARY KEY (member_id, skill_id),
	FOREIGN KEY (member_id) REFERENCES member_info (member_id),
	FOREIGN KEY (skill_id) REFERENCES skill (skill_id)
);

-- 구인-기술 매핑 테이블
CREATE TABLE recruit_skill (
	recruit_id	INT NOT NULL,
	skill_id	INT NOT NULL,
	PRIMARY KEY (recruit_id, skill_id),
	FOREIGN KEY (recruit_id) REFERENCES recruit (recruit_id),
	FOREIGN KEY (skill_id) REFERENCES skill (skill_id)
);

-- 회원-구인 카테고리 매핑 테이블
CREATE TABLE member_recruit_category (
	member_id	BIGINT NOT NULL,
	recruit_category_id	INT NOT NULL,
	PRIMARY KEY (member_id, recruit_category_id),
	FOREIGN KEY (member_id) REFERENCES member_info (member_id),
	FOREIGN KEY (recruit_category_id) REFERENCES recruit_category (recruit_category_id)
);
