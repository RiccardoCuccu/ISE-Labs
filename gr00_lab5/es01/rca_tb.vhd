library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use STD.textio.all;
use ieee.std_logic_textio.all;

USE work.constants.ALL;
 
entity rca_tb is
 
end rca_tb;
 
 
architecture behave of rca_tb is
 
  -- UUT declaration
  component ripple_carry_adder is
    generic (
      N : natural);
    port (
      i_add_term1 : in  std_logic_vector(N-1 downto 0);
      i_add_term2 : in  std_logic_vector(N-1 downto 0);
      o_result    : out std_logic_vector(N downto 0)
      );
  end component ripple_carry_adder;
 
 
  -- Internal signals definitions
  file file_VECTORS : text;
  file file_RESULTS : text;
  
  signal r_ADD_TERM1 : std_logic_vector(N-1 downto 0) := (others => '0');
  signal r_ADD_TERM2 : std_logic_vector(N-1 downto 0) := (others => '0');
  signal w_SUM       : std_logic_vector(N downto 0);
   
begin
 

-- UUT instance
GENERIC_RIPPLE_CARRY_ADDER_INST : ripple_carry_adder
    generic map (
      N => N)
    port map (
      i_add_term1 => r_ADD_TERM1,
      i_add_term2 => r_ADD_TERM2,
      o_result    => w_SUM
      );
 
 
-- Process for:
-- 1) Reading input stimuli from file
-- 2) Writing sum results to file
  process
    variable v_ILINE     : line;
    variable v_OLINE     : line;
    variable v_ADD_TERM1 : std_logic_vector(N-1 downto 0);
    variable v_ADD_TERM2 : std_logic_vector(N-1 downto 0);
    variable v_SPACE     : character;
     
  begin
 
    -- Opening input and output files in read/write modes
    file_open(file_VECTORS, "input_vectors.txt",  read_mode);
    file_open(file_RESULTS, "output_results.txt", write_mode);
 
    -- Read input stimuli from file input_vectors.txt
    while not endfile(file_VECTORS) loop
      readline(file_VECTORS, v_ILINE);
      read(v_ILINE, v_ADD_TERM1);       -- get first input
      read(v_ILINE, v_SPACE);           -- read in the space character
      read(v_ILINE, v_ADD_TERM2);	-- get second input
 
      -- Pass the variable to a signal to allow the ripple-carry to use it
      r_ADD_TERM1 <= v_ADD_TERM1;
      r_ADD_TERM2 <= v_ADD_TERM2;
 
      wait for 60 ns;
 
     -- Write output result to file output_results.txt
      write(v_OLINE, w_SUM, right, N);
      writeline(file_RESULTS, v_OLINE);
    end loop;
 
    -- Closin In/Out files
    file_close(file_VECTORS);
    file_close(file_RESULTS);
     
    wait;
  end process;
 
end behave;
