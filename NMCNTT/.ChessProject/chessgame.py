import pygame
import os
import chess
import chess.engine
import sys

def resource_path(relative_path):
    """Get absolute path to resource, works for dev and for PyInstaller"""
    try:
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")
    return os.path.join(base_path, relative_path)

# Paths
PIECES_FOLDER = resource_path("images")
STOCKFISH_PATH = resource_path("stockfish/stockfish-windows-x86-64-avx2.exe")

# AI Settings
AI_THINK_TIME = 0.5

# UI Settings
BOARD_SIZE = 800
SIDEBAR_WIDTH = 250
WIDTH = BOARD_SIZE + SIDEBAR_WIDTH
HEIGHT = 800
SQUARE_SIZE = BOARD_SIZE // 8

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
LIGHT_GREEN = (109, 152, 134)
DOT_COLOR = (242, 231, 213)
SIDEBAR_COLOR = (50, 50, 50)
BUTTON_COLOR = (200, 200, 200)
BUTTON_TEXT_COLOR = (0, 0, 0)
TO_COLOR = (255, 0, 0)      # Đỏ cho ô đến của nước đi cuối cùng của AI

# Time per player
TOTAL_TIME = 600  # 10 minutes per player

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Chess Game")
font = pygame.font.Font(None, 48)
small_font = pygame.font.Font(None, 32)

def format_time(seconds):
    """Format time as MM:SS."""
    minutes = int(seconds) // 60
    secs = int(seconds) % 60
    return f"{minutes:02}:{secs:02}"

def draw_board():
    """Draw the chessboard."""
    for row in range(8):
        for col in range(8):
            color = WHITE if (row + col) % 2 == 0 else LIGHT_GREEN
            pygame.draw.rect(screen, color, (col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE))

def draw_pieces(board):
    """Draw chess pieces on the board."""
    piece_map = {
        chess.PAWN: "pawn",
        chess.KNIGHT: "knight",
        chess.BISHOP: "bishop",
        chess.ROOK: "rook",
        chess.QUEEN: "queen",
        chess.KING: "king"
    }
    for square in chess.SQUARES:
        piece = board.piece_at(square)
        if piece:
            col = chess.square_file(square)
            row = 7 - chess.square_rank(square)
            color = "white" if piece.color else "black"
            piece_name = piece_map[piece.piece_type]
            piece_image_path = os.path.join(PIECES_FOLDER, f"{color} {piece_name}.png")
            if os.path.exists(piece_image_path):
                try:
                    piece_image = pygame.image.load(piece_image_path)
                    piece_image = pygame.transform.scale(piece_image, (SQUARE_SIZE, SQUARE_SIZE))
                    screen.blit(piece_image, (col * SQUARE_SIZE, row * SQUARE_SIZE))
                except pygame.error as e:
                    print(f"Error loading image {piece_image_path}: {e}")
            else:
                print(f"Image not found: {piece_image_path}")

def draw_timers(player_time_left, ai_time_left, turn):
    """Draw the timers for both players."""
    pygame.draw.rect(screen, SIDEBAR_COLOR, (BOARD_SIZE, 0, SIDEBAR_WIDTH, HEIGHT))

    # AI/Other Player Timer (Opponent Time) - Đặt ở trên cùng
    opponent_label = small_font.render("Opponent Time:", True, WHITE)
    opponent_time_text = font.render(format_time(ai_time_left), True, WHITE)
    screen.blit(opponent_label, (BOARD_SIZE + 30, 100))
    screen.blit(opponent_time_text, (BOARD_SIZE + 30, 150))

    # Player Timer ("Your Time") - Đặt ở dưới cùng
    player_label = small_font.render("Your Time:", True, WHITE)
    player_time_text = font.render(format_time(player_time_left), True, WHITE)
    # Tính toán vị trí Y để đặt ở dưới cùng
    player_label_y = HEIGHT - 200  # Điều chỉnh giá trị này nếu cần
    player_time_text_y = HEIGHT - 150  # Điều chỉnh giá trị này nếu cần
    screen.blit(player_label, (BOARD_SIZE + 30, player_label_y))
    screen.blit(player_time_text, (BOARD_SIZE + 30, player_time_text_y))

def draw_move_indicators(board, selected_square):
    """Draw indicators for possible moves from the selected square."""
    if selected_square is None:
        return
    
    # Lấy tất cả các nước đi hợp pháp từ quân cờ được chọn
    legal_moves = [move for move in board.legal_moves if move.from_square == selected_square]

    for move in legal_moves:
        to_square = move.to_square
        col = chess.square_file(to_square)
        row = 7 - chess.square_rank(to_square)
        center_x = col * SQUARE_SIZE + SQUARE_SIZE // 2
        center_y = row * SQUARE_SIZE + SQUARE_SIZE // 2
        radius = SQUARE_SIZE // 6  # Kích thước dấu hiệu
        
        # Vẽ hình tròn nhỏ để chỉ đường đi
        pygame.draw.circle(screen, DOT_COLOR, (center_x, center_y), radius)

def draw_last_move(last_move):
    """Draw a red border around the destination square of the last move made by AI."""
    to_square = last_move.to_square

    # Lấy thông tin cột và hàng cho ô đến
    to_col = chess.square_file(to_square)
    to_row = 7 - chess.square_rank(to_square)

    # Định nghĩa màu sắc cho dấu hiệu nước đi cuối cùng
    TO_COLOR = (207, 20, 20)  # Đỏ cho ô đến

    # Vẽ đường viền đỏ xung quanh ô đến
    pygame.draw.rect(screen, TO_COLOR, (to_col * SQUARE_SIZE, to_row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), 3)  # Đường viền đỏ dày 3 pixel

def draw_main_menu():
    """Draw the main menu."""
    screen.fill(DOT_COLOR)
    title_font = pygame.font.Font(None, 64)
    title_text = title_font.render("Chess Game", True, BUTTON_TEXT_COLOR)
    title_rect = title_text.get_rect(center=(WIDTH // 2, HEIGHT // 4))
    screen.blit(title_text, title_rect)

    button_font = pygame.font.Font(None, 48)
    play_human_button = pygame.Rect(WIDTH // 4, HEIGHT // 2 - 50, WIDTH // 2, 50)
    pygame.draw.rect(screen, BUTTON_COLOR, play_human_button)
    play_human_text = button_font.render("Play with Human", True, BUTTON_TEXT_COLOR)
    screen.blit(play_human_text, play_human_text.get_rect(center=play_human_button.center))

    play_ai_button = pygame.Rect(WIDTH // 4, HEIGHT // 2 + 50, WIDTH // 2, 50)
    pygame.draw.rect(screen, BUTTON_COLOR, play_ai_button)
    play_ai_text = button_font.render("Play with AI", True, BUTTON_TEXT_COLOR)
    screen.blit(play_ai_text, play_ai_text.get_rect(center=play_ai_button.center))

    return play_human_button, play_ai_button

def draw_ai_menu():
    """Draw the AI difficulty selection menu."""
    screen.fill(DOT_COLOR)
    title_font = pygame.font.Font(None, 64)
    title_text = title_font.render("Choose Difficulty", True, BUTTON_TEXT_COLOR)
    title_rect = title_text.get_rect(center=(WIDTH // 2, HEIGHT // 4))
    screen.blit(title_text, title_rect)

    button_font = pygame.font.Font(None, 48)
    easy_button = pygame.Rect(WIDTH // 4, HEIGHT // 2 - 60, WIDTH // 2, 50)
    pygame.draw.rect(screen, BUTTON_COLOR, easy_button)
    easy_text = button_font.render("Easy", True, BUTTON_TEXT_COLOR)
    screen.blit(easy_text, easy_text.get_rect(center=easy_button.center))

    normal_button = pygame.Rect(WIDTH // 4, HEIGHT // 2, WIDTH // 2, 50)
    pygame.draw.rect(screen, BUTTON_COLOR, normal_button)
    normal_text = button_font.render("Normal", True, BUTTON_TEXT_COLOR)
    screen.blit(normal_text, normal_text.get_rect(center=normal_button.center))

    hard_button = pygame.Rect(WIDTH // 4, HEIGHT // 2 + 60, WIDTH // 2, 50)
    pygame.draw.rect(screen, BUTTON_COLOR, hard_button)
    hard_text = button_font.render("Hard", True, BUTTON_TEXT_COLOR)
    screen.blit(hard_text, hard_text.get_rect(center=hard_button.center))

    return easy_button, normal_button, hard_button

def check_game_over(board):
    """Check if the game is over and return the result."""
    if board.is_checkmate():
        if board.turn == chess.WHITE:
            return "black_wins"  # AI vừa chiếu bí bạn
        else:
            return "white_wins"  # Bạn vừa chiếu bí AI
    elif board.is_stalemate():
        return "draw"
    elif board.is_insufficient_material():
        return "draw"
    elif board.is_seventyfive_moves():
        return "draw"
    elif board.is_fivefold_repetition():
        return "draw"
    else:
        return None

def display_game_over(result):
    """Display the game over screen with the result."""
    # Chọn màu nền
    screen.fill(DOT_COLOR)
    
    # Tạo font chữ lớn cho thông báo
    game_over_font = pygame.font.Font(None, 72)
    result_font = pygame.font.Font(None, 48)
    
    # Tạo thông báo
    if result == "white_wins":
        message = "You Win!"
    elif result == "black_wins":
        message = "You Lose!"
    elif result == "draw":
        message = "It's a Draw!"
    else:
        message = "Game Over!"
    
    # Render thông báo
    message_text = game_over_font.render(message, True, (255, 0, 0))
    message_rect = message_text.get_rect(center=(WIDTH // 2, HEIGHT // 3))
    screen.blit(message_text, message_rect)
    
    # Tạo các nút "Play Again" và "Quit"
    button_font = pygame.font.Font(None, 48)
    
    play_again_button = pygame.Rect(WIDTH // 2 - 150, HEIGHT // 2, 300, 60)
    pygame.draw.rect(screen, BUTTON_COLOR, play_again_button)
    play_again_text = button_font.render("Play Again", True, BUTTON_TEXT_COLOR)
    play_again_rect = play_again_text.get_rect(center=play_again_button.center)
    screen.blit(play_again_text, play_again_rect)
    
    quit_button = pygame.Rect(WIDTH // 2 - 150, HEIGHT // 2 + 100, 300, 60)
    pygame.draw.rect(screen, BUTTON_COLOR, quit_button)
    quit_text = button_font.render("Quit", True, BUTTON_TEXT_COLOR)
    quit_rect = quit_text.get_rect(center=quit_button.center)
    screen.blit(quit_text, quit_rect)
    
    pygame.display.flip()
    
    # Vòng lặp chờ người chơi nhấp vào nút
    waiting = True
    while waiting:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = event.pos
                if play_again_button.collidepoint(mouse_pos):
                    waiting = False
                    main()  # Khởi động lại trò chơi
                elif quit_button.collidepoint(mouse_pos):
                    pygame.quit()
                    sys.exit()

def main_menu():
    """Main menu logic."""
    while True:
        play_human_button, play_ai_button = draw_main_menu()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if play_human_button.collidepoint(event.pos):
                    return "human", None
                elif play_ai_button.collidepoint(event.pos):
                    return "ai", None

        pygame.display.flip()

def ai_menu():
    """AI difficulty selection menu logic."""
    while True:
        easy_button, normal_button, hard_button = draw_ai_menu()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if easy_button.collidepoint(event.pos):
                    return 1
                elif normal_button.collidepoint(event.pos):
                    return 10
                elif hard_button.collidepoint(event.pos):
                    return 20

        pygame.display.flip()

def reset_game():
    """Reset game state for a new match."""
    board = chess.Board()
    last_move = None  # Khởi tạo biến để lưu nước đi cuối cùng
    return board, TOTAL_TIME, TOTAL_TIME, last_move

def game_loop(board, player_time_left, ai_time_left, engine=None):
    """Main game loop."""
    clock = pygame.time.Clock()
    running = True
    selected_square = None  # Biến để lưu quân cờ đang chọn, vẫn giữ nếu cần
    last_move = None  # Biến để lưu nước đi cuối cùng của AI
    
    while running:
        dt = clock.tick(60) / 1000  # Delta time in seconds
    
        # Cập nhật thời gian
        if board.turn == chess.WHITE:
            player_time_left -= dt
        else:
            ai_time_left -= dt
    
        # Kiểm tra timeout
        if player_time_left <= 0:
            result = "black_wins"
            running = False
        elif ai_time_left <= 0:
            result = "white_wins"
            running = False
        else:
            result = check_game_over(board)
            if result:
                running = False
    
        screen.fill(DOT_COLOR)
        draw_board()
        draw_pieces(board)
        draw_timers(int(player_time_left), int(ai_time_left), board.turn)
        
        # Vẽ các dấu hiệu di chuyển nếu có
        draw_move_indicators(board, selected_square)
        
        # Vẽ nước đi cuối cùng của AI nếu có
        if last_move:
            draw_last_move(last_move)
    
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN and board.turn == chess.WHITE:
                mouse_x, mouse_y = event.pos
                col, row = mouse_x // SQUARE_SIZE, mouse_y // SQUARE_SIZE
                square = chess.square(col, 7 - row)
    
                if selected_square is None:
                    # Chọn quân cờ nếu quân cờ thuộc sở hữu người chơi
                    piece = board.piece_at(square)
                    if piece and piece.color == chess.WHITE:
                        selected_square = square
                else:
                    # Thực hiện di chuyển nếu quân cờ được chọn
                    move = chess.Move(selected_square, square)
                    if move in board.legal_moves:
                        board.push(move)
                        selected_square = None
                        # Sau khi người chơi di chuyển, kiểm tra kết quả
                        result = check_game_over(board)
                        if result:
                            running = False
                    else:
                        # Nếu quân cờ mới được chọn, cập nhật `selected_square`
                        piece = board.piece_at(square)
                        if piece and piece.color == chess.WHITE:
                            selected_square = square
                        else:
                            selected_square = None
    
        # Xử lý nước đi của AI
        if board.turn == chess.BLACK and engine:
            try:
                result_move = engine.play(board, chess.engine.Limit(time=AI_THINK_TIME))
                board.push(result_move.move)
                last_move = result_move.move  # Cập nhật nước đi cuối cùng
                # Sau khi AI di chuyển, kiểm tra kết quả
                result = check_game_over(board)
                if result:
                    running = False
            except Exception as e:
                print(f"Error making AI move: {e}")
                running = False
    
        pygame.display.flip()
    
    # Sau khi vòng lặp kết thúc, hiển thị màn hình kết quả nếu có
    if result:
        display_game_over(result)
        # Nếu người chơi chọn "Play Again", khởi tạo lại trò chơi
        # Nếu người chơi chọn "Quit", trò chơi đã được thoát trong hàm `display_game_over`
    else:
        pygame.quit()

def main():
    # Main menu logic
    mode, skill_level = main_menu()

    engine = None
    if mode == "ai":
        skill_level = ai_menu()
        try:
            engine = chess.engine.SimpleEngine.popen_uci(STOCKFISH_PATH)
            engine.configure({"Skill Level": skill_level})
        except Exception as e:
            print(f"Failed to initialize engine: {e}")
            sys.exit()

    board, player_time_left, ai_time_left, last_move = reset_game()
    game_loop(board, player_time_left, ai_time_left, engine)

    if engine:
        engine.quit()

if __name__ == "__main__":
    main()
