module tff(p, pbar, q, qbar, r, rbar, clk);
  input clk;
  output reg p = 0, pbar = 1, q = 0, qbar = 1, r = 0, rbar = 1;
  
  always @(posedge clk) begin
    if (r) begin
      p <= ~p;
      pbar <= ~pbar;
    end
  end
  
  always @(posedge clk) begin
    if (pbar) begin
      q <= ~q;
      qbar <= ~qbar;
    end
  end
  
  always @(posedge clk) begin
    if (qbar) begin
      r <= ~r;
      rbar <= ~rbar;
    end
  end
endmodule
