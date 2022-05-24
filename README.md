# 21020120_MaiThanhHai_DuAnCuoiKi
Đây là dự án cuối kì, môn Lập trình nâng cao (INT2215_1) của Mai Thanh Hải (MSV: 21020120).

Đề tài: làm game tuỳ chọn

Tên: VoyagerX

Ngôn ngữ: C++

IDE: Visual Studio Code & SDL2

Các nguồn tham khảo:

-	Ý tưởng game: https://www.youtube.com/watch?v=QgDR8LrRZhk&pp=ugMICgJ2aRABGAE%3D

-	Framework: https://www.youtube.com/playlist?list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Hướng dẫn cài đặt
-	Bước 1: Truy cập vào đường link https://github.com/MaiHaingo/21020120_MaiThanhHai_DuAnCuoiKi.git 
-	Bước 2: Vào mục Code (màu xanh lá bên phải màn hình), chọn Download ZIP và tải thư mục về nơi mong muốn.
-	Bước 3: Giải nén thư mục.
-	Bước 4: Trong thư mục giải nén, tìm file có tên ‘main.exe’ và chạy.
2.	Mô tả về trò chơi
-	Người chơi sẽ là người điều khiển con tàu hình tam giác, khởi đầu ở chính giữa khung hình với 3 mạng và 0 điểm.
-	Điều khiển:
    - Phím UP ARROW: tăng tốc 
	- Phím LEFT ARROW: chuyển hướng sang trái
	- Phím RIGHT ARROW: chuyển hướng sang phải
	- Phím SPACE: bắn đạn
	- Lưu ý: con tàu trôi dạt trong không gian nên sẽ chỉ tiến chứ không phanh, nếu muốn dừng lại thì phải quay ngược con tàu và tăng tốc.
-	Nếu người chơi bắn trúng 1 thiên thạch mẹ thì nó sẽ phân tách làm 2 thiên thạch con, đồng thời sinh tiếp 1 thiên thạch mẹ mới ngẫu nhiên. Nếu bắn trúng thiên thạch con thì nó sẽ biến mất luôn và không sinh thêm gì cả.
-	Với mỗi thiên thạch bị bắn trúng (mẹ hoặc con), người chơi sẽ được 10đ.
-	Nếu tàu va chạm với thiên thạch thì người chơi mất 1 mạng. Khi hết số mạng, người chơi đã thua và có thể thoát (ấn phím ‘ESC’).
3.	Mô tả về chức năng
-	Link youtube: https://youtu.be/Hq3D5APqCaQ
4.	Kỹ thuật lập trình
-	Lập trình hướng đối tượng: kĩ thuật xuyên suốt dự án, chia các công cụ và vật thể của game thành các Lớp và thư viện khác nhau để dễ quản lí.
-	Đồ hoạ: sử dụng thư viện SDL2, phối hợp cùng với các thư viện khác như SDL_image, SDL_ttf, SDL_mixer để khởi tạo và kết xuất hình ảnh, chữ, âm thanh lên màn hình.
-	Xử lí input: nhận đầu vào từ bàn phím để thay đổi hình ảnh và sự kiện trong game.
-	Multiple displays: sử dụng 2 màn hình là Menu và màn hình chơi.
-	Thời gian: tính toán thời gian, giới hạn tỉ lệ khung hình để game chạy với cùng tốc độ trên các nền tảng khác nhau, dùng thời gian cho các xử lí vật lí trong game.
-	Lớp: xây dựng các nhóm đối tượng thành các Lớp khác nhau, có các thuộc tính và phương thức đặc trưng để thuận tiện cho việc làm game.
-	Vòng lặp: trò chơi lặp lại và diễn ra liên tục.
-	Điều kiện rẽ nhánh: kiểm tra các trạng thái của trò chơi để dẫn đến các kết quả mong muốn.
-	Hàm: thực hiện các chức năng mong muốn mà không lặp lại code.
-	Con trỏ: sử dụng con trỏ để tránh khởi tạo một đối tượng nhiều lần, gây thất thoát bộ nhớ.
-	Mảng và duyệt mảng: trong game sử dụng Lớp vector để đưa các đối tượng cùng loại vào một mảng để thuận tiện cho việc cập nhật trạng thái của các đối tượng đó.
-	Map: quản lí tài nguyên và các đường dẫn.
-	Sinh số ngẫu nhiên.
-	Biến đếm: tính điểm.
-	Các công thức toán học, vật lí: các công thức tính vận tốc, toạ độ, góc quay, khoảng cách.
5.	Kết luận
- Điều tâm đắc
    - Tự mình làm một dự án game từ đầu, phải tìm hiểu các kiến thức mới và áp dụng vào code của mình.
    - Game chạy được khá suôn sẻ, các lỗi đã được khắc phục khá tốt.
- Hạn chế
    - Game còn khá đơn điệu, chưa nhiều tính năng lạ.
    - Quản lí bộ nhớ chưa tốt, game còn hơi lag.
    - Code vẫn còn khá dài.
- Hướng phát triển
    - Tối ưu hoá code và quản lí bộ nhớ tốt hơn để game chạy mượt hơn.
    - Đưa thêm các tính năng mới vào trò chơi: 
        - Chơi lại.
        - Chơi nhiều người.
        - Xây dựng thêm các lớp địch có thể bắn về phía người chơi.
        - Xây dựng thêm các loại đạn, các chiêu thức khác.
        - Xây dựng trò chơi thành các level hoặc stage khác nhau.
        - Xây dựng một bảng ghi lại điểm cao của từng lần chơi.

